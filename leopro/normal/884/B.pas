program Project1;

var
  a: array of LongInt;
  n, x, i: LongInt;

procedure ReadArray(var a: array of LongInt; n: LongInt);
begin
  For i := 0 to n-1 do
  If i < n-1 then Read(a[i]) else ReadLn(a[i]);
end;

begin
  Read(n);  ReadLn(x);
  SetLength(a, n);
  ReadArray(a, n);
  x := x - (n-1);
  For i := 0 to n-1 do x := x - a[i];
  If x = 0 then WriteLn('YES') else WriteLn('NO'); 
end.