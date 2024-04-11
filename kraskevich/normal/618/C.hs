import Data.Int (Int64)
import Data.Monoid (mappend)
import Data.Maybe (fromJust)
import Data.List (minimumBy, sortBy)
import qualified Data.ByteString.Char8 as B

data Point = Point Int64 Int64 Int deriving (Eq)

getId (Point _ _ id) = id

diff (Point x1 y1 id1) (Point x2 y2 _) = Point (x1 - x2) (y1 - y2) id1

vecProd (Point x1 y1 _) (Point x2 y2 _) = x1 * y2 - x2 * y1

len2 (Point x y _) = x * x + y * y

cmpAngle p1 p2 = (compare (vecProd p1 p2) 0) `mappend` compare (len2 p1) (len2 p2)

cmpCoords (Point x1 y1 _) (Point x2 y2 _) = compare x1 x2 `mappend` compare y1 y2

leftAndRest ps = (p0, sortBy cmpAngle $ map (flip diff $ p0) (filter (/= p0) ps))
    where p0 = minimumBy cmpCoords ps 

firstNonColinear ps = head $ (filter (\p -> p `vecProd` (head ps) /= 0) ps)

solve ps = (getId p0, getId $ head rest, getId $ firstNonColinear rest) 
    where (p0, rest) = leftAndRest ps

makePoints coords = map (\(i, (x, y)) -> Point x y i) $ zip [1..n] coords
    where n = length coords 

getInt = fromIntegral . fst . fromJust . B.readInt

getCoords line = (getInt x, getInt y)
    where [x, y] = B.words line

main = do
    input <- B.getContents
    let (line:lines) = B.lines input
    let points = makePoints $ map getCoords lines
    let (i0, i1, i2) = solve points
    putStrLn $ show i0 ++ " " ++ show i1 ++ " " ++ show i2