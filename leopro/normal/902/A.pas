type
  TTeleport = Record
    Location, Limit: LongInt;
  end;

var
  N, Friend, i, j: LongInt;
  Teleports: array [1..100] of TTeleport;
  CanGoPoint: array [0..100]  of Boolean;

procedure Yes(Cond: Boolean);
begin
  If Cond then WriteLn('YES') else WriteLn('NO');
end;

begin
  Read(N, Friend);
  ReadLn;
  For i := 1 to Friend do CanGoPoint[i] := False;
  CanGoPoint[0] := True;
  For i := 1 to N do
  begin
    Read(Teleports[i].Location, Teleports[i].Limit);
    ReadLn;
  end;
  For i := 1 to N do
  begin
   If CanGoPoint[Teleports[i].Location] then
   For j := Teleports[i].Location to Teleports[i].Limit do CanGoPoint[j] := True;
  end;
  Yes(CanGoPoint[Friend]);
  ReadLn;
end.