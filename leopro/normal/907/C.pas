program C454;

var
  N, i, j, counter, str, whatwrite: LongInt;
  c: char;
  s: string;
  TrueChar: array ['a'..'z'] of Boolean;

begin
  ReadLn(N);
  whatwrite:=-1;
  For c := 'a' to 'z' do TrueChar[c] := True;

  For str := 0 to N-1 do
  begin
    ReadLn(s);
    N := N;
      If s[1] = '.' then
      begin
        For j := 3 to Length(s) do
        begin
          TrueChar[s[j]] := False;
        end;
      end;
      If s[1] = '!' then
      begin
        For c := 'a' to 'z' do
        begin
          If Pos(c, s) = 0 then TrueChar[c] := False;
        end;
      end;
      If s[1] = '?' then
      begin
        TrueChar[s[3]] := False;
      end;
      counter := 0;
      For c := 'a' to 'z' do
      begin
        If TrueChar[c] then counter:=counter+1;
      end;
      If counter = 1 then
      begin
        whatwrite := (N-1 - str);
        Break;
      end;
  end;
  For i := str+1 to N-1 do
  begin
      ReadLn(s);
      If s[1] = '.' then whatwrite:=whatwrite-1;
  end;
  whatwrite:=whatwrite-1;
  If whatwrite < 0 then whatwrite:=0;
  WriteLn(whatwrite);   
end.