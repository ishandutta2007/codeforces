var
  n: Int32;

begin
  ReadLn(n);
  n := n - 1;
  n := n div 2;
  If n mod 2 = 0 then WriteLn('1') else WriteLn('0');
end.