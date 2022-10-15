program Project1;

var
  s: string;

begin
  ReadLn(s);
  If ord(s[1]) > 93 then s[1] := chr(ord(s[1])-32);
  WriteLn(s); readln;
end.