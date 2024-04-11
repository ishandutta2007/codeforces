var t,n,r,j,i:longint;ans:int64;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n,r);ans:=0;
    if r>n then r:=n;
    ans:=trunc((1+r)/2*r); 
    if r=n then ans:=ans-n+1;
    writeln(ans);
  end;
end.