uses
Math;

var
  m, d, x: Int32;
const
  Months: array [1..12] of Int32 = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

begin
  ReadLn(m, d);
  x := d - 1;
  x += Months[m];
  WriteLn(ceil(x / 7));
  ReadLn;
end.