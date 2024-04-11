uses
  Math;

var
  k, l, d, t, time, m, n, ans, chicken, x: Extended;

begin
  ReadLn(k, d, t);
  l := d - (round(k) mod round(d));
  If l = d then l := 0; 
  m := 1/t;
  time := k*m+l*m/2;
  n := trunc(1/time); 
  ans := (k+l)*n;
  chicken := time*n;
  chicken := 1 - chicken;
  x := chicken / m;
  If x > k then x := k;
  ans := ans + x;
  If x = k then
  begin
    x := (chicken-(x*m)) / m*2;
    ans := ans + x;
  end;
  WriteLn(ans:0:10); 
end.