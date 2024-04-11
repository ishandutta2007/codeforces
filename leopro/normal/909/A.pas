program Project1;

var
  Name, SurName, Ans: string;
  Space, i: LongInt;
  Ended: Boolean;

function SuperTrim(var s: string): LongInt;
var
  plus, i: LongInt;
begin
  plus := 0;
  For i := Length(s) downto 1 do
  begin
    If ord(s[i+plus]) < 33 then
    begin
      Delete(s, i+plus, 1);
      Result := i+plus;
      inc(plus);
    end;
  end;
end;

begin
  ReadLn(Name);
  Space := SuperTrim(Name);
  SurName := '';
  For i := Space to Length(Name) do
  begin
    SurName := SurName + Name[Space];
    Delete(Name, Space, 1);
  end;
  Ans := Name[1];
  Ended := False;
  For i := 2 to Length(Name) do
  begin
    If Name[i] < SurName[1] then
    begin
      Ans := Ans + Name[i]
    end else
    begin
      Ans := Ans + SurName[1];
      Ended := True;
      Break;
    end;
  end;
  If not Ended then Ans := Ans + SurName[1];
  WriteLn(Ans);
end.