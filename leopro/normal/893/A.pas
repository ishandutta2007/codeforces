program Project1;

var
  Player: array [1..3] of Boolean;
  N, i, p: LongInt;
  Correct: Boolean;

begin
  Correct := True;
  Player[1] := True;
  Player[2] := True;
  Player[3] := False;
  ReadLn(N);
  For i := 1 to N do
  begin
    ReadLn(p);
    Player[1] := not Player[1];
    Player[2] := not Player[2];
    Player[3] := not Player[3];
    Player[p] := not Player[p];
    If Player[p] = false then Correct:=False;
  end;
  If Correct then WriteLn('YES') else WriteLn('NO');  
end.