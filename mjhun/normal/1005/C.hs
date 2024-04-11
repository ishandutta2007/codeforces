import qualified Data.Map.Strict as Map

toint s = (read s) :: Integer

agregar x m = Map.insertWith (+) x 1 m
quitar :: Integer -> (Map.Map Integer Integer) -> (Map.Map Integer Integer)
quitar x m = Map.insertWith (+) x (-1) m

doit :: [Integer] -> (Map.Map Integer Integer) -> [Integer] -> Integer
doit [] s p = 0
doit (x:xs) s p =
	let ss = quitar x s in
	if any (\t -> (Map.findWithDefault 0 (t-x) ss) > 0) p then
		doit xs s p
	else
		1 + (doit xs s p)

asdasd [] = Map.fromList []
asdasd (x:xs) = agregar x (asdasd xs)

solve::String -> String
solve ss =
	let x = Prelude.map toint (tail (words ss)) in
	let s = asdasd x in
	let p = Prelude.map (\x -> 2^x) [0..30] in
	let r = doit x s p in
	(show r) ++ "\n"

main = do
  interact $ solve