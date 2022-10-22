import Data.List

solve :: [Int] -> Int
solve a = head . sort $ map (\(c,x) -> c + 1 - fromEnum(x==f) - fromEnum(x==l)) cnt
  where
    b = map head $ group a
    cnt = map (\a -> (length a, head a)) $ group $ sort b
    f = head b
    l = last b

main :: IO ()
main = interact $ unlines . map show . f . map (map read . words) . tail . lines
  where f(_:x:xs) = solve x : f(xs)
        f[] = []