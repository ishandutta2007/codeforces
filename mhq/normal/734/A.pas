program zhopa;
var
n : integer;
mx : integer;
last : integer;
cur : integer;
val : integer;
i : integer;
c : ansistring;
bal : integer;
begin
readln(n);
readln(c);
bal := 0;
for i := 1 to n do
begin
  if (c[i] = 'A') then
    inc(bal)
  else
    dec(bal);
end;
if (bal > 0) then
  writeln('Anton')
else if (bal = 0) then
  writeln('Friendship')
else
  writeln('Danik')

end.