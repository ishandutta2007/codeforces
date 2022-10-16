var
  a, b: Int64;

begin
  ReadLn(a, b);
  While (a > 0) and (b > 0) do
  begin
    If (a < 2*b) and (b < a*2) then Break;
    If a >= 2*b then
    begin
      a := a mod (2*b);
    end else
    begin
      b := b mod (a*2);
    end;
  end;
  WriteLn(a, ' ', b);
  readln;
end.