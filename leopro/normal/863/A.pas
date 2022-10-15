uses
  sysutils;
var
  x, i:LongInt;
  s: string;
  IsPalindrom: Boolean;
  
begin
  ReadLn(x);
  While x mod 10 = 0 do x := x div 10;
  s := IntToStr(x);
  IsPalindrom := True;
  For i := 1 to Length(s) do if s[i] <> s[Length(s)+1-i] then IsPalindrom := False;
  If IsPalindrom then WriteLn('YES') else WriteLn('NO');
end.