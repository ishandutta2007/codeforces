uses
Math;

var
  n, R:Int32;

begin
  ReadLn(n, R);
  WriteLn( (sin(pi / n)* R) / (1 - sin(pi / n)) : 0 : 7);
  ReadLn;
end.