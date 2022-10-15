var
  s: string;
  i: Int32;
  
begin
  ReadLn(s);
  For i := Length(s) downto 1 do s := s + s[i];
  WriteLn(s);
end.