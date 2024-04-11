var t,i,n,j:longint;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    if n mod 2=1 then
    begin
      write(7);
      n:=n-2;
    end;
    for j:=1 to n div 2 do write(1);
    writeln;
  end;
end.