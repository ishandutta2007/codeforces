var
  n, x, y, i, cnt: Int32;
  a: array [1..100] of int32;

begin
  ReadLn(n, x, y);
  for i := 1 to n do Read(a[i]);
  readln;
   if x > y then
   begin
     WriteLn(n);
     Exit;
   end;
   while true do
  begin
    cnt := 0;
    for i := 1 to n do
      if (a[i] <= x) and (a[i] > 0) then cnt += 1;
    WriteLn(cnt - (cnt div 2));
    Exit;
    end;
    readln; readln;
end.