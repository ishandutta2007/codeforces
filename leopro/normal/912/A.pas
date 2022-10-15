uses
  Math;

var
  A, B, x, y, z, NeedA, NeedB: Int64;

begin
  Read(A, B, x, y, z);
  ReadLn; ReadLn;

  NeedA := x*2 + y;
  NeedB := y + z*3;

  NeedA := max(NeedA - A, 0);
  NeedB := max(NeedB - B, 0);

  WriteLn(NeedA + NeedB);
end.