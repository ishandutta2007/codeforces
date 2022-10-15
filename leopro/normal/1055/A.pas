var
  n,  s, i: Int32;
  Stations: array [0..1, 1..1000] of Boolean;
  Station: Int32;

begin
  ReadLn(n, s);
  For i := 1 to  n  do
  begin
    Read(Station);
    If Station = 0 then Stations[0, i] := False else Stations[0, i] := True;
  end;
  ReadLn;
  For i := 1 to  n  do
  begin
    Read(Station);
    If Station = 0 then Stations[1, i] := False else Stations[1,i] := True;
  end;
  ReadLn;
  If not (Stations[0, s]) and not (Stations[1, s]) then
  begin
    WriteLn('NO');
    Exit;
  end;
  If not Stations[0, 1] then
  begin
    WriteLn('NO');
    Exit;
  end;
  If Stations[0, s] then
  begin
    WriteLn('YES');
    Exit;
  end;
  Station := 0;
  For i := s+1 to n do
  begin
    If (Stations[0, i]) and (Stations[1, i]) then Station:=i;
  end;
  If Station = 0 then
  begin
    WriteLn('NO');
    Exit;;
  end;
  WriteLn('YES');
    Exit;

end.