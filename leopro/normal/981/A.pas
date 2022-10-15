var
  s: string;
  i, len: Int32;
  palindrome, same: Boolean;
  
  begin
    ReadLn(s);
    Len := Length(s);
    palindrome := True;
    same := True;
    For i := 1 to len do
    begin
      If s[i] <> s[len+1-i] then palindrome := False;
      If i < len then If s[i] <> s[i+1] then same := False;
    end;
    If same then
    begin 
      writeLn(0);
      Exit;
    end;
    If palindrome then
    begin 
      writeLn(len-1);
      Exit;
    end;
    writeLn(len);
  end.