program Project1;

var
  s: string;
  n, i: LongInt;
  Div64: Boolean;

begin
  ReadLn(s);
  Div64:=True;
  For i := 1 to Length(s) do
  begin
    n := Pos('0', s);
    If n = 1 then Delete(s, 1, 1);
  end;
  For i := 1 to 6 do
  begin
    n := Pos('0', s);
    If n = 0 then
    begin
      Div64:=False;
      Break;
    end;
    Delete(s, 1, n);
  end;
  If Div64 then WriteLn('yes') else WriteLn('no'); 
end.