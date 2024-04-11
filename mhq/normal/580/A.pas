program zhopa;
var
n : integer;
mx : integer;
last : integer;
cur : integer;
val : integer;
i : integer;
begin
readln(n);
for i := 0 to n - 1 do
begin
  read(cur);
  if (last <= cur) then
    inc(val)
  else
  begin
    if (mx < val) then
      mx := val;
    val := 1;
  end;
  last := cur;
end;
if (mx < val) then
  mx := val;
writeln(mx)
end.