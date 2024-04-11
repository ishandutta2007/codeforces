uses math;

function gcd (a,b : int64) : int64;
var remainder: int64;
begin
  while not (b=0) do
    begin
      remainder := a mod b;
      a := b;
      b := remainder;
    end;
  gcd :=a;
end;

var n, a, b, p, q, lcm: int64;
    ans : int64;
begin
     ans := 0;
     read(n,a,b,p,q);
     lcm := a*(b div gcd(a,b));
     ans := ans + ((n div a) - (n div lcm))*p;
     ans := ans + ((n div b) - (n div lcm))*q;
     ans := ans + (n div lcm) * max(p,q);
     write(ans);
     readln;
     readln;
end.