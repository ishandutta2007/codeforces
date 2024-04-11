var
  a, b, c, d, sum: Int64;
  
begin
  ReadLn(a, b, c, d);
  sum := a + b + c + d;
  sum := sum div 3;
  if a <> sum then Write(sum - a, ' ');
  if b <> sum then Write(sum - b, ' ');
  if c <> sum then Write(sum - c, ' ');
  if d <> sum then Write(sum - d, ' ');
end.