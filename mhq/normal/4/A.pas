program zhopa;
var
w : integer;
begin
readln(w);
if ((w mod 2 = 1) or (w = 2)) then
  writeln('NO')
else
  writeln('YES')
end.