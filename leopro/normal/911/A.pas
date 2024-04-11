uses
Math;

var
  a: array [0..100000] of LongInt;
  N, Minimum, i, pos1, pos2, distance: LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do Read(a[i]);
  readLn;
end;

function ArrayMin(a: array of LongInt; N: LongInt): LongInt;
begin
  Result := a[0];

  For i := 0 to N - 1 do
  If Result > a[i] then Result := a[i];
end;

begin
  ReadLn(N);
  ReadArray(a, N);
  Minimum := ArrayMin(a, N);
  pos1 := -N - 1;
  pos2 := -N - 1;
  distance := N + 1;
  For i := 0 to N-1 do
  begin
    If a[i] = Minimum then
    begin
      pos1 := pos2;
      pos2 := i;
      distance:=Min(distance, pos2 - pos1);
    end;
  end;
  WriteLn(distance);
end.