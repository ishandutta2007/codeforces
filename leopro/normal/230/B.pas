program Project1;

var
  n, i: LongInt;
  a: array [1..100000] of Int64;

procedure ReadArray(var a: array of Int64; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

function IsEasy(n: LongInt): Boolean;
var
  i: LongInt;
begin
  Result := True;
  For i := 2 to round(sqrt(n)) do
  begin
    If n mod i = 0 then Result := False;
  end;
  If n = 1 then Result := False;
end;

begin
  Read(n);
  ReadArray(a, n);
  For i := 1 to n do
  begin
    If (sqrt(a[i]) = round(sqrt(a[i]))) and (IsEasy(round(sqrt(a[i])))) then
    WriteLn('YES') else WriteLn('NO');
  end;
end.