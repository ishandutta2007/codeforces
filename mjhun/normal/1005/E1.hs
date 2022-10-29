import qualified Data.Map.Strict as Map
import Data.List as List
import Data.Maybe

slice from to xs = take (to - from + 1) (drop from xs)

toint s = (read s) :: Integer

agregar x m = Map.insertWith (+) x 1 m
quitar :: Integer -> (Map.Map Integer Integer) -> (Map.Map Integer Integer)
quitar x m = Map.insertWith (+) x (-1) m

doit [] t m = [t]
doit (x:xs) t m =
    if x > m then
        t:(doit xs (t+1) m)
    else
        t:(doit xs (t-1) m)

doit2 [] w = 0
doit2 (x:xs) w =
    (Map.findWithDefault 0 (1-x) w) + (Map.findWithDefault 0 (-x) w) + doit2 xs w

asdasd [] = Map.fromList []
asdasd (x:xs) = agregar x (asdasd xs)

solve::String -> String
solve ss =
    let sss = Prelude.map toint (tail (words ss)) in
    let (m:s) = sss in
    let k = fromJust $ List.elemIndex m s in
    let w = asdasd (doit (slice (k+1) 2222222 s) 0 m) in
    let t = doit (reverse (slice 0 (k-1) s)) 0 m in
    let r = doit2 t w in
    (show r) ++ "\n"

main = do
  interact $ solve