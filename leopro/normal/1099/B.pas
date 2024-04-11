uses
Math;

var
  n, w, h: Int32;

begin
  ReadLn(n);
  w := ceil(sqrt(n));
  h := ceil(n / w);

  WriteLn(w + h);
  ReadLn;
end.