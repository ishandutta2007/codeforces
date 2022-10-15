var
  n, m, i: LongInt;
  yuanes, amount, ans: Extended;
  
begin
  ReadLn(n, m);
  ans := 100000;
  For i := 1 to n do
  begin
    ReadLn(yuanes, amount);
    yuanes := yuanes/amount;
    If yuanes < ans then ans := yuanes;
  end;
  WriteLn((ans*m):0:7);
end.