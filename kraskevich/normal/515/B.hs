import Data.Char
import Data.List
import Data.Int
import Data.Maybe
import Control.Monad
import qualified Data.Sequence as Seq
import qualified Data.Set as Set
import Data.Foldable(toList)
import qualified Data.ByteString.Char8 as B

readInt :: IO Int
readInt = head `liftM` readIntList
         
readIntList :: IO [Int]
readIntList = do
    line <- B.getLine
    let res = map (fst . fromJust . B.readInt) $ B.words line
    return res

readString :: IO String
readString = do
    line <- B.getLine
    return $ B.unpack line
    
makeStep :: Set.Set (Int, Int) -> ([Bool], [Bool]) -> ([Bool], [Bool])
makeStep goodPairs (boys, girls) = 
    (boys', girls') 
    where
        n = length boys
        m = length girls
        happyPairs = [(bi, gi) | (b, bi) <- zip boys [0..], 
                                 (g, gi) <- zip girls [0..],
                                 (b || g) && (bi, gi) `Set.member` goodPairs] 
        happyBoys = Set.fromList $ map fst happyPairs
        happyGirls = Set.fromList $ map snd happyPairs
        boys' = map (`Set.member` happyBoys) [0..n - 1]
        girls' = map (`Set.member` happyGirls) [0..m - 1]
        
main = do
    [n, m] <- readIntList
    happyBoys <- tail `liftM` readIntList
    happyGirls <- tail `liftM` readIntList
    let boys = map (`elem` happyBoys) [0..n - 1]
    let girls = map (`elem` happyGirls) [0..m - 1]
    let goodPairs = Set.fromList $ map (\d -> (d `mod` n, d `mod` m)) [0..n * m - 1]
    let (boys', girls') = foldr (.) id (replicate (n + m) (makeStep goodPairs)) 
            $ (boys, girls)
    let allHappy = not (False `elem` (boys' ++ girls'))    
    let ans = if allHappy then "Yes" else "No"
    putStrLn $ ans