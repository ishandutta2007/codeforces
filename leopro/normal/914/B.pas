var
  numbers: array [1..100000] of LongInt;
  N, i, x: LongInt;
  
begin
  For i := 1 to 100000 do numbers[i] := 0;
  ReadLn(N);
  For i := 1 to N do
  begin
    Read(x);
    inc(numbers[x]);
  end;
  ReadLn;
  For i := 1 to 100000 do
  begin
    If numbers[i] mod 2 = 1 then 
    begin
      WriteLn('Conan');
      Exit;
    end;
  end;
  WriteLn('Agasa');
end.