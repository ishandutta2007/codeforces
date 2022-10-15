program project1;

var
  s1, s2: string;
  MaxDivider, i, j, X: LongInt;
  a: array [1..2000] of LongInt;
  b: array [1..2000] of string;
  Divider: Boolean;

function NOD(Number1, Number2: LongInt):LongInt;
var
  Change: LongInt;
begin
  For i := 1 to Number1 + Number2 do
  begin
    If Number1 > Number2 then
    begin
      Change := Number1;    Number1 := Number2;    Number2 := Change;
    end;
    If Number2 > Number1 then
    begin
      Number2 := Number2 - Number1
    end;
    If Number2 = Number1 then
    begin
      Result := Number1;
    end;
  end;
end;

function Dividers(Number: LongInt):LongInt;
var
  Divs, N: LongInt;
  Square: Boolean;
begin
  N := 0;
  Divs:=0;
  Square:=False;
  For i := 1 to round(sqrt(Number)) do
  begin
    If Number mod i = 0 then
    begin
      Divs := Divs + 1;
      N := N + 1;
      a[N] := i;
      If i <> Number div i then
      begin
        N := N + 1;
        a[N] := Number div i;
      end else Square := True;
    end;
  end;
  Divs := Divs * 2;
  If Square then Divs := Divs - 1;

  Result := Divs;
  If Number = 2 then
  begin
    Result := 2;
    a[1] := 1;
    a[2] := 2;
  end;
end;

begin
  ReadLn(s1);  ReadLn(s2);
  MaxDivider := NOD(Length(s1), Length(s2));
  X := Dividers(MaxDivider);
  For i :=  1 to X do
  begin
    b[i] := Copy(s1, 1, a[i]);
    j := 1;
    Divider:=True;
    While j <= Length(s1) do
    begin
      If Copy(s1, j, a[i]) <> b[i] then Divider:=False;
      j := j + a[i];
    end;
    j := 1;
    While j <= Length(s2) do
    begin
      If Copy(s2, j, a[i]) <> b[i] then Divider:=False;
      j := j + a[i];
    end;
    If not Divider then X := X-1;
  end;
  WriteLn(X);
  ReadLn;
end.