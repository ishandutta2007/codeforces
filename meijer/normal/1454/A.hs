solve n = [2..n] ++ [1]
main = interact $ unlines . map (unwords . map show) . map solve . tail . map read . words