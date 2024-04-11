var
  n, i, m, j, station: Int32;
  Number: array [1..100] of Boolean;
  Stations: array [1..100] of Boolean;

begin
  ReadLn(n);
  For i := 1 to 100 do Number[i] := True;
  For i := 1 to n do
  begin
    Read(m);
    For j := 1 to 100 do Stations[j] := false;
    For j := 1 to m do
    begin
      Read(station);
      stations[station] := True;
    end;
    ReadLn;
    For j := 1 to 100 do If (Stations[j] = False) then Number[j] := False;
  end;
  For i := 1 to 100 do If Number[i] then Write(i, ' ');
  ReadLn;
end.