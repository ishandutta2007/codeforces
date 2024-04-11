var
  N, i: LongInt;
  a: array [1..100] of LongInt;
  
begin
  ReadLn(N);
  For i := 1 to N do ReadLn(a[i]);
  
  For i := 1 to N do
  begin
    If (a[i] = 1) or (a[i] = 2) or (a[i] = 4) or (a[i] = 5) or (a[i] = 8) or (a[i] = 11) then WriteLn('NO') else WriteLn('YES');
  end;
end.