uses math;
var n,i:longint;ans:int64;b,bl:array[-1000000..1000000]of int64;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(b[i]);
    b[i]:=b[i]-i;
    bl[b[i]]:=bl[b[i]]+b[i]+i;
  end;
  ans:=0;
  for i:=1 to n do
    ans:=max(ans,bl[b[i]]);
  writeln(ans);
end.