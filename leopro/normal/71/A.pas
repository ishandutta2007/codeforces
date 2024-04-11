program Project1;

uses
  sysutils;

var
  n, i: SmallInt;
  s: array [1..100] of string;

begin
  ReadLn(n);
  For i := 1 to n do
  begin
    ReadLn(s[i]);
  end;
  For i := 1 to n do
  begin
    If Length(s[i]) > 10 then s[i] := s[i][1] + IntToStr(Length(s[i])-2) + s[i][Length(s[i])];
    WriteLn(s[i]);
  end;
end.