var
  N, i: Int32;
  Money: array [1..200000] of Int32;
  x, f: Int32;
  ans, add: Int64;

begin
  ReadLn(N);
  For i := 1 to N do Read(Money[i]);
  ReadLn;
  ReadLn(x, f);
  ans := 0;
  For i := 1 to N do
  begin
    add := Money[i] div (x+f);
    inc(ans, add);
    If Money[i] - add*(x+f) > x then inc(ans)
  end;
  ans := ans*f;
  WriteLn(ans);
end.