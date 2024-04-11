import Data.List
import Data.Int
import Control.Monad

solve :: Int64 -> Int64 -> Int64
solve _ 0 = 0
solve a b = a `div` b + solve b (a `mod` b)

main = do
    line <- getLine
    let [a, b] = map read $ words line
    print $ solve a b