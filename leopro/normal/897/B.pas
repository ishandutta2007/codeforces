program Project1;

uses
  Math, sysutils;

var
  k, p, i, j: LongInt;
  sum: Int64;

function StrToStrrtS(s: string): string;
begin
  For i := Length(s) downto 1 do
  begin
    s := s+s[i];
  end;
  Result := s;
end;

begin
  Read(k); ReadLn(p);
  sum := 0;
  For j := 1 to k do
  begin
    sum := sum + StrToInt64(StrToStrrtS(IntToStr(j)));
  end;
  WriteLn(sum mod p);
end.