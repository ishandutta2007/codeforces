import Data.Char
import Data.List

minBalance :: String -> Char -> Int
minBalance s c = snd $ foldl' addChar (0, 0) s 
    where
        addChar acc@(cur, low) x 
            | x == c = (cur - 1, min (cur - 1) low)
            | x == toLower c = (cur + 1, low)
            | otherwise = acc

main = do  
    _ <- getLine
    s <- getLine
    print $ sum $ map (abs . minBalance s) ['A'..'Z']