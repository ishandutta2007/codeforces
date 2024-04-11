var
  N, k, i: Int32;

begin
  ReadLn(N, k);
  For i := 1 to k do
  begin
    If N mod 10 > 0 then N := N-1 else N := N div 10;
  end;
  WriteLn(N);
end.