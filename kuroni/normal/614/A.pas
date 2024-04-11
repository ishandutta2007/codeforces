uses math;

var l, r, k: int64;
    a, b, i: longint;

begin
  read(l,r,k);
  b := trunc(ln(r)/ln(k));
  a := trunc(ln(l)/ln(k));
  if intpower(k,b) > r then dec(b);
  if intpower(k,a) < l then inc(a);
  if b < a then write('-1') else for i := a to b do write(trunc(intpower(k,i)),' ');
end.