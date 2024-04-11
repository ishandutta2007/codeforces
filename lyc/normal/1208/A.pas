var t,i,a,b,c:longint;f:array[0..3]of longint;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(a,b,c);
    f[0]:=a;f[1]:=b;
    c:=c mod 3;
    f[2]:=a xor b;
    writeln(f[c]);
  end;
end.