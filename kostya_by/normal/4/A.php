<?php
    $n = fgets(STDIN);
    $ans = "YES";
    if ($n == 2 || $n % 2 == 1) $ans = "NO";
    echo $ans;
?>