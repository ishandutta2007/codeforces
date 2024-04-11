import Data.List

solve :: [Int] -> Int
solve a
  | null b = -1
  | otherwise = snd . head . head $ b
  where
    b = filter ((==1) . length). groupBy (\x y -> fst x == fst y) . sort $ zip a [1..]

f [] = []
f (_:x:xs) = solve x : f xs

main = interact $
  unlines . map show . f . tail . map (map read) . map words . lines