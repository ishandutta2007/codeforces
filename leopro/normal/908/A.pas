
var
  s: string;
  i, counter: LongInt;

begin
  ReadLn(s);
  counter:=0;
  For i := 1 to Length(s) do
  begin
    If (s[i] = '1') or (s[i] = '3') or (s[i] = '5') or (s[i] = '7') or (s[i] = '9') or (s[i] = 'a') or (s[i] = 'e') or
       (s[i] = 'i') or (s[i] = 'o') or (s[i] = 'u') then inc(counter);
  end;
  WriteLn(counter);
end.