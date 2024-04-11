import qualified Data.ByteString.Char8 as B

calcDp :: Int -> Int -> Double -> [Double]
calcDp n 0 _ = 1.0 : replicate (n - 1) 0.0
calcDp n t p =
    let prev = calcDp n (t - 1) p
        prevPairs = zip prev (0.0 : prev)
    in map (\ (cur, old) -> cur * (1.0 - p) + old * p) prevPairs

calcExpectation :: [Double] -> Double
calcExpectation ps = 
    let e1 = sum $ map (\ (i, p) -> i * p) (zip [0..] ps) 
        e2 = fromIntegral (length ps) * (1.0 - sum ps)
    in e1 + e2 
 
main = do
    line <- getLine
    let [w1, w2, w3] = words line
    let n = (read w1) :: Int
    let t = (read w3) :: Int
    let p = (read w2) :: Double
    let dp = calcDp n t p 
    let res = calcExpectation dp
    putStrLn $ show res