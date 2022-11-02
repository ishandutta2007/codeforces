import Data.List
import Data.Int
import Data.Map

getDifference :: String -> String -> Int
getDifference xs ys = length . Data.List.filter (\ (a, b) -> a /= b) $ zip xs ys
 
getPositions :: String -> String -> Map (Char, Char) Int
getPositions xs ys = 
    Data.List.foldl' (\ acc (x, y, pos) -> Data.Map.insert (x, y) pos acc) 
           empty (zip3 xs ys [1..])

findBest :: [((Char, Char), Int)] -> (Int, Int, Int)
findBest entries =
    let res@(delta, p1, p2) = 
            Data.List.foldl' max (0, -1, -1) 
            [getCost x y | x <- entries, y <- entries]
    in if delta == 0 then (0, -1, -1) else res
    where
        getMatching :: (Char, Char) -> (Char, Char) -> Int
        getMatching (a1, b1) (a2, b2) =
            let m1 = if a1 == b1 then 1 else 0
                m2 = if a2 == b2 then 1 else 0
            in m1 + m2
        getCost :: ((Char, Char), Int) -> ((Char, Char), Int) -> (Int, Int, Int)
        getCost ((a1, b1), p1) ((a2, b2), p2) =
            (getMatching (a1, b2) (a2, b1) - getMatching (a1, b1) (a2, b2), p1, p2) 

main = do
    getLine
    s <- getLine
    t <- getLine
    let positions = getPositions s t
    let entries = zip (keys positions) (elems positions)
    let (delta, p1, p2) = findBest entries
    putStrLn $ show (getDifference s t - delta)
    putStrLn $ show p1 ++ " " ++ show p2