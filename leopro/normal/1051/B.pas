var
  i, L, R: Int64;
  
begin
  ReadLn(L, R);
  WriteLn('YES');
  i := L;
  While i <= R do
  begin
    WriteLn(i+1, ' ', i);
    inc(i, 2);
  end;
end.