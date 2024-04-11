program Project1;

var
  s: string;
  i, max: SmallInt;

function HowManyVK(s: string): SmallInt;
var
  x, n: SmallInt;
begin
  n := 0;
  For x := 1 to Length(s) do
  begin
    If (s[x] = 'V') and (s[x+1] = 'K') then n := n+1;
  end;
  Result := n;
end;

function ChangeSymbol(s: string; n: SmallInt): string;
begin
  If s[n] = 'V' then s[n] := 'K' else s[n] := 'V';
  Result := s;
end;

begin
  ReadLn(s);
  max := HowManyVK(s);
  For i := 1 to Length(s) do
  begin
    s := ChangeSymbol(s, i);
    If max < HowManyVK(s) then max := HowManyVK(s);
    s := ChangeSymbol(s, i);
  end;
  WriteLn(max);
end.