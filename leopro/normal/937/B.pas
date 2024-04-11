uses
  Math;

var
  p, y, i, j: LongInt;
  Good: Boolean;

begin
  ReadLn(p, y);
  For i := y downto p+1 do
  begin
    Good := True;
    For j := 2 to min(round(sqrt(i)), p) do If i mod j = 0 then Good := False;
    If Good then
    begin
      WriteLn(i);
      Exit;
    end;
  end;
  WriteLn('-1');
end.