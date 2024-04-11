program Project1;

var
  x, n: LongInt;

function HowMany(a, b: LongInt): LongInt;
var
  i, counter: LongInt;
begin
  counter := 0;
  For i := 1 to b do
  begin
    If (b mod i = 0) and (i <= a) and (b div i <= a) then counter := counter + 1;
    If i > a then Break;
  end;
  Result := counter;
end;

begin
  Read(n); ReadLn(x);
  WriteLn(HowMany(n, x)); ReadLn;
end.