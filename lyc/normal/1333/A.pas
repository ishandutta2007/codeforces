var t,i1,n,m,sum,b,w,i,j:longint;
begin
  readln(t);
  for i1:=1 to t do
  begin
    readln(n,m);
    write('W');
    for i:=2 to m do write('B');
    writeln;
    for i:=2 to n do
    begin
      for j:=1 to m do write('B');
      writeln;
    end;
  end;
end.