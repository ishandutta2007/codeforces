var n,m,a,b,k:int64;
function min(a,b:int64):int64;begin if a<b then exit(a);exit(b);end;
begin
  read(n,m,a,b);
  k:=n div m;
  writeln(min((m*(k+1)-n)*a,(n-m*k)*b));
end.