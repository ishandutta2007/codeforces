program Project1;

var
  n, def, i: LongInt;
  a: array [1..100] of LongInt;
  progression: Boolean;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

begin
  ReadLn(n);
  ReadArray(a, n);
  def := a[2] - a[1];
  progression := True;
  For i := 3 to n do
  begin
    If def <> a[i] - a[i-1] then progression := False;
  end;
  If progression then WriteLn(a[n] + def) else WriteLn(a[n]);
end.