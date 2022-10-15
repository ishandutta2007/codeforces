var
  n, i, ans, x: Int32;
  
begin
  ReadLn(n);
  ans := 0;
  For i := 1 to n do
  begin
    Read(x);
    inc(ans, abs(x));
  end;
  WriteLn(ans);
end.