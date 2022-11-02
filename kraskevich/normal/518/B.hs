import Data.List
import qualified Data.Map as DM
import Data.Maybe

getMap :: String -> DM.Map Char Int
getMap = foldl' (\ acc x -> DM.insertWith (+) x 1 acc) DM.empty  

solve :: String -> String -> (Int, Int)
solve s t = 
    let m1 = getMap s
        m2 = getMap t
    in foldl' (\ (a, b) (c1, c2) -> 
                let (a1, b1) = getBest m1 m2 c1 c2 in (a + a1, b + b1)) 
              (0, 0)
              (zip ['a'..'z'] ['A'..'Z'])  
    where 
        getBest :: DM.Map Char Int -> DM.Map Char Int -> Char -> Char -> (Int, Int)
        getBest m1 m2 lower upper = 
            let cntLower1 = fromMaybe 0 (DM.lookup lower m1)
                cntLower2 = fromMaybe 0 (DM.lookup lower m2)
                cntUpper1 = fromMaybe 0 (DM.lookup upper m1)
                cntUpper2 = fromMaybe 0 (DM.lookup upper m2)
                goodLower = min cntLower1 cntLower2
                goodUpper = min cntUpper1 cntUpper2
                rest1 = cntLower1 + cntUpper1 - goodLower - goodUpper
                rest2 = cntLower2 + cntUpper2 - goodLower - goodUpper
                rest = min rest1 rest2
            in (goodLower + goodUpper, rest)
     
main = do
    s <- getLine
    t <- getLine
    let (a, b) = solve s t
    putStrLn $ show a ++ " " ++ show b